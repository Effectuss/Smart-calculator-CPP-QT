#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <list>
#include <stdexcept>
#include <string>
#include <vector>

class Token {
public:
  enum class TypeTokens {
    kNumber = 1,
    kOpenParenthesis,
    kCloseParenthesis,
    kBinaryOperator,
    kUnaryOperator,
    kFunction
  };

  Token(const TypeTokens &type, const std::string &token,
        const short &priority = -1);

  short GetPriority() const;
  std::string GetTokenString() const;
  TypeTokens GetType() const;

  bool IsNumber() const;
  bool IsFunction() const;
  bool IsOpenParenthesis() const;
  bool IsCloseParenthesis() const;
  bool IsBinaryOperator() const;
  bool IsUnaryOperator() const;

private:
  std::pair<TypeTokens, std::string> type_and_token_;
  short priority_;
};

#endif // __TOKEN_H__
