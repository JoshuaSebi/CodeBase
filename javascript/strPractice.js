/*Prompt the user to enter their full name
Generate a user name for them based on the input
Start username with @ followed by their full name and ending 
with the full name length*/

fname = prompt("Enter your first name");
lname = prompt("Enter your last name");

name = fname + lname;
userName = `@${name}${name.length}`;
console.log(userName);
