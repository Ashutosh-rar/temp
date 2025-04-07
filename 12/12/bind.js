const EventEmitter = require('events');


const myEmitter = new EventEmitter();


myEmitter.on('greet', () => {
    console.log('Listener 1: Hello, welcome!');
});


myEmitter.on('greet', () => {
    console.log('Listener 2: How are you today?');
});


console.log('Emitting the greet event...\n');
myEmitter.emit('greet');

// run node bind.js in the terminal