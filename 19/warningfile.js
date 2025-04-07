const fs = require('fs');
const fileName = 'file1.txt'; //try changing file names for error and warning message 


console.log('Node.js application has started successfully!');


fs.access(fileName, fs.constants.F_OK, (err) => {
    if (err) {
        
        console.error(`Error: The file '${fileName}' was not found.`);
    } else {
        
        console.warn(`Warning: The file '${fileName}' already exists!`);
        
        
        fs.readFile(fileName, 'utf8', (readErr, data) => {
            if (readErr) {
                console.error(`Error reading file: ${readErr.message}`);
            } else {
                console.log(`File Content:\n${data}`);
            }
        });
    }
});

//create file1.txt file