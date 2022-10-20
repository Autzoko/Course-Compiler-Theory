# LAB 1 词法分析程序设计实现
## 语法设定
G[<单词符号>] --> <标识符>$\epsilon$ | <无符号整数>$\epsilon$ | <单字符分界符>$\epsilon$ | <双字符分界符>$\epsilon$  
<标识符> --> [a-z A-Z] | <标识符>[a-z A-Z] | <标识符>[0-9]
<无符号整数> --> [0-9] | <无符号整数>[0-9]
<单字符分界符> --> + | - | * | ; | , | ( | ) | { | } | %
<双字符分界符> --> <大于>= | <小于>= | <小于>> | <感叹号>= | <等于>= | <斜竖>* | <加号>+︱<加号>=︱<减号>-︱<减号>=︱<星号>=︱<斜竖>=︱<大于>>︱<小于><︱<与符号>&︱<竖线>|︱<斜竖>/︱<星号>/
<小于> --> <
<等于> --> =
<大于> --> >
<斜竖> --> /
<感叹号> --> !
<加号> --> +
<减号> --> -
<星号> --> *
<与符号> --> &

## 类别编码
| 单词符号 | 类别编码 | 单词符号 | 类别编码 |
|---|---|---|---|
|标识符|1|}|24|
|无符号整数|2|>|25|
|void|3|<|26|
|int|4|=|27|
|float|5|!|28|
|double|6|/|29|
|if|7|>=|30|
|else|8|<=|31|
|for|9|!=|32|
|do|10|==|33|
|while|11|%|34|
|return|12|++|35|
|break|13|--|36|
|+|14|+=|37|
|-|15|-=|38|
|*|16|*=|39|
|;|17|/=|40|
|,|18|>>|41|
|(|19|<<|42|
|)|20|&&|43|
|[|21|\|\||44|
|]|22|\||45|
|{|23|&|46|