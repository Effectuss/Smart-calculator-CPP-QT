#include <gtest/gtest.h>

#include <cstdio>

#include "../model/model.h"

namespace s21 {
typedef std::vector<std::array<double, 4>> test_type;

void fill_data_for_credit(CreditCalc::DataForCredit &data, double sum_credit,
                          double amount_month, double interest_rate,
                          CreditCalc::TypeOfCredit type) {
  data.sum_credit = sum_credit;
  data.amount_month = amount_month;
  data.interest_rate = interest_rate;
  data.type_credit = type;
}

void compare_data(test_type &data_from_calcus, test_type &my_data) {
  for (size_t i = 0; i < data_from_calcus.size(); ++i) {
    for (size_t j = 0; j < data_from_calcus.at(0).size(); ++j) {
      char buffer_my[300] = "\0";
      char buffer_calcus[300] = "\0";
      sprintf(buffer_my, "%.1f", my_data.at(i).at(j));
      sprintf(buffer_calcus, "%.1f", data_from_calcus.at(i).at(j));
      ASSERT_STREQ(buffer_my, buffer_calcus);
    }
  }
}

TEST(CreditCalcAnnuity, test1) {
  Model model;
  CreditCalc::DataForCredit data;
  fill_data_for_credit(data, 3'000'000.0, 24.0, 13.0,
                       CreditCalc::TypeOfCredit::kAnnuity);
  model.GetCreditCalc().CalculateCredit(data);
  test_type from_calcus = {{142625.47, 110125.47, 32500.00, 2889874.53},
                           {142625.47, 111318.49, 31306.97, 2778556.04},
                           {142625.47, 112524.44, 30101.02, 2666031.59},
                           {142625.47, 113743.46, 28882.01, 2552288.14},
                           {142625.47, 114975.68, 27649.79, 2437312.46},
                           {142625.47, 116221.25, 26404.22, 2321091.21},
                           {142625.47, 117480.31, 25145.15, 2203610.87},
                           {142625.47, 118753.02, 23872.45, 2084857.85},
                           {142625.47, 120039.51, 22585.96, 1964818.44},
                           {142625.47, 121339.94, 21285.53, 1843478.40},
                           {142625.47, 122654.53, 19971.02, 1720824.03},
                           {142625.47, 123983.21, 18642.26, 1596840.8},
                           {142625.47, 125326.36, 17299.11, 1471514.38},
                           {142625.47, 126684.06, 15941.41, 1344830.4},
                           {142625.47, 128056.47, 14569.00, 1216773.85},
                           {142625.47, 129443.75, 13181.72, 1087330.10},
                           {142625.47, 130846.06, 11779.41, 956484.14},
                           {142625.47, 132263.56, 10361.91, 824220.48},
                           {142625.47, 133696.41, 8929.06, 690524.07},
                           {142625.47, 135144.79, 7480.68, 555379.28},
                           {142625.47, 136608.86, 6016.61, 418770.54},
                           {142625.47, 138088.79, 4536.68, 280681.74},
                           {142625.47, 139584.74, 3040.72, 141096.88},
                           {142625.47, 141096.92, 1528.55, -0.00}};
  compare_data(from_calcus, data.data_for_table);
}

TEST(CreditCalcDifferentiated, test2) {
  Model model;
  CreditCalc::DataForCredit data;
  fill_data_for_credit(data, 3'000'000, 24.0, 13.0,
                       CreditCalc::TypeOfCredit::kDifferentiated);
  model.GetCreditCalc().CalculateCredit(data);
  test_type from_calcus = {{157500.00, 125000.00, 32500.00, 2875000.00},
                           {156145.83, 125000.00, 31145.83, 2750000.00},
                           {154791.67, 125000.00, 29791.67, 2625000.00},
                           {153437.50, 125000.00, 28437.50, 2500000.00},
                           {152083.33, 125000.00, 27083.33, 2375000.00},
                           {150729.17, 125000.00, 25729.17, 2250000.00},
                           {149375.00, 125000.00, 24375.00, 2125000.00},
                           {148020.83, 125000.00, 23020.83, 2000000.00},
                           {146666.67, 125000.00, 21666.67, 1875000.00},
                           {145312.50, 125000.00, 20312.50, 1750000.00},
                           {143958.33, 125000.00, 18958.33, 1625000.00},
                           {142604.17, 125000.00, 17604.17, 1500000.00},
                           {141250.00, 125000.00, 16250.00, 1375000.00},
                           {139895.83, 125000.00, 14895.83, 1250000.00},
                           {138541.67, 125000.00, 13541.67, 1125000.00},
                           {137187.50, 125000.00, 12187.50, 1000000.00},
                           {135833.33, 125000.00, 10833.33, 875000.00},
                           {134479.17, 125000.00, 9479.17, 750000.00},
                           {133125.00, 125000.00, 8125.00, 625000.00},
                           {131770.83, 125000.00, 6770.83, 500000.00},
                           {130416.67, 125000.00, 5416.67, 375000.00},
                           {129062.50, 125000.00, 4062.50, 250000.00},
                           {127708.33, 125000.00, 2708.33, 125000.00},
                           {126354.17, 125000.00, 1354.17, 0.00}};
  compare_data(from_calcus, data.data_for_table);
}

}  // namespace s21