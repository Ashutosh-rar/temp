
const readline = require('readline');
const rl = readline.createInterface({
input: process.stdin,
output: process.stdout
});

function validateStudentForm() {
rl.question('Enter student name: ', (name) => {
rl.question('Enter age: ', (age) => {
rl.question('Enter email: ', (email) => {
if (isValidAge(age) && isValidEmail(email)) {

console.log('\nStudent Registration Successful!');
console.log(`Name: ${name}`);
console.log(`Age: ${age}`);
console.log(`Email: ${email}`);
rl.close();
}
else {
console.log('Invalid input. Please check your age and email format.');
rl.close();
}
});
});
});
}

function isValidAge(age) {
return /^\d+$/.test(age) && parseInt(age) > 0;
}

function isValidEmail(email) {
const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
return emailRegex.test(email);
}

validateStudentForm();