const fs = require('fs');

const inputFile = 'input.txt';
const outputFile = 'output.txt';

const searchWord = 'hello';     
const replaceWord = 'hi';        

fs.readFile(inputFile, 'utf8', (err, data) => {
  if (err) return console.error('Error reading file:', err);

  
  const replacedText = data.replaceAll(
    new RegExp(searchWord, 'gi'),
    `**${replaceWord}**`
  );

  fs.writeFile(outputFile, replacedText, err => {
    if (err) return console.error('Error writing file:', err);
    console.log('Word replaced and bolded. Output saved to output.txt');
  });
});
