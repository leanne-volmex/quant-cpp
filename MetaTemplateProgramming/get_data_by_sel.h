template <typename I, typename H>
template <typename T, typename F, typename... Ts>
DataFrame<I, H> DataFrame<I, H>::
    get_data_by_sel(const char *name, F &sel_functor) const
{

    const ColumnVecType<T> &vec = get_column<T>(name);
    const size_type idx_s = indices_.size();
    const size_type col_s = vec.size();
    StlVecType<size_type> col_indices;

    col_indices.reserve(idx_s / 2);
    for (size_type i = 0; i < col_s; ++i)
        if (sel_functor(indices_[i], vec[i]))
            col_indices.push_back(i);

    DataFrame df;
    IndexVecType new_index;

    new_index.reserve(col_indices.size());
    for (auto citer : col_indices)
        new_index.push_back(indices_[citer]);
    df.load_index(std::move(new_index));

    const SpinGuard guard(lock_);

    load_columns<Ts...>(col_indices, idx_s, df);

    return df;
}

template <typename I, typename H, typename... Ts>
void DataFrame<I, H>::load_columns(const StlVecType<size_type> &col_indices,
                                   const size_type idx_s,
                                   DataFrame<I, H> &df) const
{
    for (const auto &col_citer : column_list_)
    {
        sel_load_functor_<size_type, Ts...> functor(
            col_citer.first.c_str(),
            col_indices,
            idx_s,
            df);

        data_[col_citer.second].change(functor);
    }
}
/*updated version, load_columns is a recursive variadic function that loads columns of different types until all types have been processed.
The base case of the recursion is the specialization of load_columns that takes no template parameters and does nothing.*/
template <typename I, typename H>
template <typename... Ts>
void DataFrame<I, H>::load_columns(const StlVecType<size_type> &,
                                   const size_type,
                                   DataFrame<I, H> &) const
{
}

// https://godbolt.org/z/Ka4z6hcbj  [original 5 pars version]
