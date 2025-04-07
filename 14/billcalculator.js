function calculateBill(units) {
    let billAmount = 0;
  
    if (units <= 100) {
      billAmount = units * 1.50;
    } else if (units <= 200) {
      billAmount = 100 * 1.50 + (units - 100) * 2.00;
    } else if (units <= 300) {
      billAmount = 100 * 1.50 + 100 * 2.00 + (units - 200) * 2.50;
    } else {
      billAmount = 100 * 1.50 + 100 * 2.00 + 100 * 2.50 + (units - 300) * 3.00;
    }
  
    return billAmount;
  }
  
  module.exports = { calculateBill };