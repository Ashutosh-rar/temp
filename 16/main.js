const EventEmitter = require('events');


const eventEmitter = new EventEmitter();


eventEmitter.on('dataReceived', (data) => {
    console.log(`Data received: ${data}`);
});


let count = 1;

const interval = setInterval(() => {
    if (count > 5) {
        clearInterval(interval); 
        console.log("Event loop stopped.");
    } else {
        console.log(`Triggering event ${count}`);
        eventEmitter.emit('dataReceived', `Message ${count}`);
        count++;
    }
}, 2000); 

//run node main.js