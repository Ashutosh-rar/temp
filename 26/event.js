// eventExample.js
const EventEmitter = require('events');

// Create a custom class
class MyEmitter extends EventEmitter {}

// Instantiate it
const myEmitter = new MyEmitter();

// Bind an event
myEmitter.on('greet', () => {
  console.log('Hello! Event has been triggered.');
});

// Raise the event
myEmitter.emit('greet');
