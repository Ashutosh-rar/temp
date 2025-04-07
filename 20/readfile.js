const fs = require('fs');
const EventEmitter = require('events');


const eventEmitter = new EventEmitter();


eventEmitter.on('readFile', (fileName) => {
    fs.readFile(fileName, 'utf8', (err, data) => {
        if (err) {
            console.error(`Error reading file: ${err.message}`);
            return;
        }
        console.log(`File Content:\n${data}`);
    });
});


const fileName = 'file1.txt';


eventEmitter.emit('readFile', fileName);

//create file1.txt file
