# LAB1 Implementation of Lexical Analyzer

## Grammar Settings
G[\<Word Symbol\>] --> \<Identifier\> $\epsilon$ | \<Unsigned Int\> $\epsilon$ | \<Single Char\> $\epsilon$ | \<Double Char\> $\epsilon$  

\<Identifier\> --> [a-z A-Z] | \<Identifier\>[a-z A-Z] | \<Identifier\>[0-9]

\<Unsigned Int\> --> [0-9] | \<Unsigned Int\>[0-9]

\<Single Char\> --> + | - | * | ; | , | ( | ) | { | } | %

\<Double Char\> --> \<Greater-than\>= | \<Less-than\>= | \<Less-than\>> | \<Not\>= | \<Equal\>= | \<Divide\>* | \<Add\>+︱\<Add\>=︱\<Minus\>-︱\<Minus\>=︱\<Multiple\>=︱\<Divide\>=︱\<Greater-than\>>︱\<Less-than\><︱\<And\>&︱\<Or\>|︱\<Divide\>/︱\<Multiple\>/

\<Less Than\> --> <
\<Equal\> --> =
\<Greater-than\> --> >
\<Divide\> --> /
\<Not\> --> !
\<Add\> --> +
\<Minus\> --> -
\<Multiple\> --> *
\<And\> --> &
\<Or\> --> |

## Categorical Codes
| Word Symbol | Categorical Code | Word Symbol | Categorical Code |
|---|---|---|---|
|Identifier|1|}|24|
|Unsigned Int|2|>|25|
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
| | |/*|47|
| | |*/|48|
| | |//|49|

## Results
text 1：
```c
int main()
{
	int a = 1;
	int b = 123;
	int c = 999;
	float array[512];
	while(a > 0)
	{
		a = b + c;
		c = b;
		b = a;
		if(a > 0)
		{
			array[i++] = a;
		}
		else
		{
			break;
		}
	}
}
```
Process result：
```
(4,int)(1,main)(19,()(20,))
(23,{)
(4,int)(1,a)(27,=)(2,1)(17,;)
(4,int)(1,b)(27,=)(2,123)(17,;)
(4,int)(1,c)(27,=)(2,999)(17,;)
(5,float)(1,array)(21,[)(2,512)(22,])(17,;)
(11,while)(19,()(1,a)(25,>)(2,0)(20,))
(23,{)
(1,a)(27,=)(1,b)(14,+)(1,c)(17,;)
(1,c)(27,=)(1,b)(17,;)
(1,b)(27,=)(1,a)(17,;)
(7,if)(19,()(1,a)(25,>)(2,0)(20,))
(23,{)
(1,array)(21,[)(1,i)(35,++)(22,])(27,=)(1,a)(17,;)
(24,})
(8,else)
(23,{)
(13,break)(17,;)
(24,})
(24,})
(24,})
```
Text 2：
```c
int main()
{
	float c = 10;
	float a, b = 2;
	a = b + c;
	c = a++ + ++b;
	return 0;
}
```
process result：
```
(4,int)(1,main)(19,()(20,))
(23,{)
(5,float)(1,c)(27,=)(2,10)(17,;)
(5,float)(1,a)(18,,)(1,b)(27,=)(2,2)(17,;)
(1,a)(27,=)(1,b)(14,+)(1,c)(17,;)
(1,c)(27,=)(1,a)(35,++)(14,+)(35,++)(1,b)(17,;)
(12,return)(2,0)(17,;)
(24,})
```


