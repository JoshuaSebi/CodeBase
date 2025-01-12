//Simple calculator using functions

function add(a, b) {
  console.log(a + b);
}

sub = (a, b) => {
  console.log(a - b);
};

mult = (a, b) => {
  console.log(a * b);
};

function div(a, b) {
  console.log(a / b);
}

x = prompt("Enter first number");
y = prompt("Enter second number");
opt = prompt("1.Add\n2.Subtract\n3.Multiply\n4.Divide\nEnter option");
switch (opt) {
  case 1:
    add(x, y);
  case 2:
    sub(x, y);
  case 3:
    mult(x, y);
  default:
    div(x, y);
}
