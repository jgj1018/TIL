# Chapter 1

* To express a tuple of length one as a literal, a comma must be placed after the element, but within the parentheses. For example, (17,) is a one-element tuple. The reason for this requirement is that, without the trailing comma, the expression (17) is viewed as a simple parenthesized numeric expression.


* Python carefully extends the semantics of `//` and `%` to cases where one or both operands are negative. For the sake of notation, let us assume that variables n and m represent respectively the dividend and divisor of a quotient n/m, and that `q = n // m` and `r = n % m`. Python guarantees that `q * m + r` will equal n. (...) Python further guarantees that 0 <= r < m. As a consequence, we find that `-27 // 4` evaluates to -7 and `-27 % 4` evaluates to 1, as `(-7)*4 +1 = -27`. When the divisor is negative, Python guarantees that m < r <= 0. As an example, `27 // -4 is -7` and `27 % -4` is -1, satisfying the identity `27 = (-7) * (-4) + (-1)`


* Python also supports the use of negative indices, which denote a distance from the end of the sequence; index -1 denotes the last element. index =2 the second to last.

