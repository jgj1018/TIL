# Design of an Kotlin Practice Project

- OOP programming - kotlin
- Small amount of project
- No framework
- Coffee shop

(1) [on the console] Customer check menu
[Espresso Cafelatte Americano Cappuccino]
*Each menu has properties name, price, ingredient 
(2) Customer orders a cup of coffee. 
[one cup per one person]
(3) Customer Hands over money
(4) Order list updated.
(5) Shop makes a cup of coffee.
(6) Shop hands over the cup of coffee.
 
[Used Design Pattern]

Factory Pattern
[interface]

- Menu 

[Class]

- Espresso extends Menu
- Cafelatte extends Menu
- Americano extends Menu
- Cappuccino extends Menu

[Properties]
- menu_id
- name
- price
- recipe (array)

[method]

====================================================================

[Class]

- Shop

[Properties]

- menu_list
- order_list

[method]

- showMenuList()
- takeOrder(input_value)
- takeMoney(input_value)
- isValidOrder(input_value) : validation
- isValidMoney(input_value) : validation 
- MenuFactory(menu_id) : Factory Pattern

====================================================================

[Interface]

- Ingredient

[Class]

- (not defined yet)
 
[Properties]

- ingredient_id
- name

