# C1-Префикс и суффикс

На стандартном потоке ввода задаются две символьные строки, разделённые символом перевода строки. Каждая из строк не превышает подлине 104. В строках не встречаются пробельные символы. На стандартный поток вывода напечатайте два числа, разделённых пробелом: первое число — длина наибольшего префикса первойстроки, являющегося суффиксом второй; второе число — наоборот, длина наибольшего суффикса первой строки, являющегося префиксомвторой. Сравнение символов проводите с учётом регистра (т.е. символы 'a' и 'A' различны).

## Пример №1
Данные на входе: 
```
don't_panic
nick_is_a_mastodon
```  
Данные на выходе: `3 3`

## Пример №2
Данные на входе: 
```
monty_python
python_has_list_comprehensions
```  
Данные на выходе: `0 6`