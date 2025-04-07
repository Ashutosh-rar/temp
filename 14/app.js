const readline = require('readline');
const { calculateBill } = require('./billCalculator');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of units consumed: ', (units) => {
  const billAmount = calculateBill(parseFloat(units));
  console.log(`Your electricity bill amount is: $${billAmount.toFixed(2)}`);
  rl.close();
});

//create billcalculator.js file
//run node app.js
