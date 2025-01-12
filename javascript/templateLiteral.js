/*Enables user to give the variables along 
with the strings instead of splitting into substrings
The variables are written within ${varname}
CONSIDER THE EXAMPLE*/

obj = {
  name: "ABC",
  age: 21,
  class: "CSBS",
};

let op = `Name = ${obj.name}\nAge = ${obj.age}\nClass = ${obj.class}`;
console.log(op);

/* OUTPUT
Name = ABC
Age = 21
Class = CSBS
*/
