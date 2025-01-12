//for loop
let sum = 0;
for (i = 1; i <= 5; i = i + 1) {
  sum += i;
}
console.log("Sum = ", sum);

//for-of loop
str = "abcdef";
for (i of str) {
  console.log(i); //iterates thr a,b,c....f
}

//for-in loop
str = "abcdef";
for (i in str) {
  console.log(i); //gives index of elements
}
