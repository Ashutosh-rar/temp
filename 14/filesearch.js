const fs = require('fs'); // Import the file system module

const fileName = 'file1.txt'; // File to read (any text file)
const searchWord = 'python'; // Word to search for

// Read the file asynchronously
fs.readFile(fileName, 'utf8', (err, data) => {
    if (err) {
        console.error('Error reading file:', err);
        return;
    }

    const lines = data.split('\n'); // Split file content into lines
    let count = 0;

    console.log(`Searching for "${searchWord}" in ${fileName}...\n`);

    lines.forEach((line, index) => {
        if (line.includes(searchWord)) {
            count++;
            console.log(`Found in line ${index + 1}: ${line}`);
        }
    });

    console.log(`\nTotal occurrences of "${searchWord}": ${count}`);
});

//create file1.txt file
//run node slip14q1/filesearch.js