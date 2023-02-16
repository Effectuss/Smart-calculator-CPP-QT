#ifndef __CALCCONTROLLER_H__
#define __CALCCONTROLLER_H__

#include "model.h"

namespace s21 {
class Controller {
 public:
  Controller(Model *model) : model_{model} {};
  double CalculateMath(std::string &str_from_label, double &x);

 private:
  Model *model_;
};
}  // namespace s21

#endif  // __CALCCONTROLLER_H__