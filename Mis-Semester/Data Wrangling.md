+ echo 'aba' | sed 's/[ab]//'

 ba

+ echo 'ababzac' | sed 's/[ab]//g'

zc

+ echo 'ababzac' | sed -E 's/(ab)*//g'

zac

- `.` means “any single character” except newline
  `.` 表示“除换行符外的任何单个字符”
- `*` zero or more of the preceding match
  `*` 前面匹配的零个或多个
- `+` one or more of the preceding match
  `+` 前面的一个或多个匹配项
- `[abc]` any one character of `a`, `b`, and `c`
  `[abc]` `a` 、 `b` 和 `c` 中的任意一个字符
- `(RX1|RX2)` either something that matches `RX1` or `RX2`
  `(RX1|RX2)` 匹配 `RX1` 或 `RX2` 的内容
- `^` the start of the line
  `^` 行首
- `$` the end of the line
  `$` 行尾