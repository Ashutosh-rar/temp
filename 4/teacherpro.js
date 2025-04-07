const readline = require('readline');
const rl = readline.createInterface({
input: process.stdin,
output: process.stdout
});

function createTeacherProfile() {
rl.question('Enter teacher name: ', (name) => {
rl.question('Enter subject: ', (subject) => {
rl.question('Enter years of experience: ', (experience) => {

console.log('\nTeacher Profile:');
console.log(`Name: ${name}`); 
console.log(`Subject: ${subject}`);
console.log(`Experience: ${experience} years`);
rl.close();
});
});
});
}

createTeacherProfile();