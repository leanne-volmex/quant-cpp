#include<vector>
#include<string>

struct OptionData {
    double strike_price;
    double volatility;
    std::string type;
    std::string expiration_date;
    double underlying_price;
    double implied_volatility;
    double delta;
    double gamma;
    double theta;
    double vega;
    double rho;
};
/* possible implementation
int main()
{
    std::vector<OptionData> options;
    options.push_back({113.45, 0.01, "CALL", "2021-07-01", 100.00, 0.02, 0.50, 0.01, -0.01, 0.05, 0.03});
    options.push_back({378.90, 0.02, "PUT", "2023-03-01", 150.00, 0.03, -0.30, 0.02, -0.02, 0.04, 0.02});
}
*/

