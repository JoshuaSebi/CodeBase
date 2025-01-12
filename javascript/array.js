let color = ["Black", "Green", "Blue", "Yellow"];

color.push("Red"); //Add at the end
color.push("Violet");
console.log(color);

color.pop(); //Delete from end
console.log(color);

len = color.length; //Give length
console.log(`Length = ${len}`);

arr2 = ["Cyan", "Pink"];
inter = color.concat(arr2); //add another array to the end
console.log(inter);

color.unshift("Red"); //Add element to the beginning
console.log(color);

color.shift(); //Remove from beginning
console.log(color);

subarray = color.slice(2, 5); //Obtain a sub array
console.log(subarray);

color.forEach((col) => {
  console.log(col);
});
