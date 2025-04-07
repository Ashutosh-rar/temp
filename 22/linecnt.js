const fs = require('fs');

fs.readFile('sample.txt', 'utf8', (err, data) => {
  if (err) {
    console.error('Error reading file:', err);
    return;
  }
  const lines = data.split('\n').length;
  console.log(`Number of lines in the file: ${lines}`);
});
