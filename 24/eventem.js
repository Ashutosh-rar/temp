const EventEmitter = require('events');

function createEmitter() {
  const emitter = new EventEmitter();

  // Emit event after 2 seconds
  setTimeout(() => {
    emitter.emit('greet', 'Hello from EventEmitter!');
  }, 2000);

  return emitter;
}

// Get the emitter from function
const myEmitter = createEmitter();

// Bind to event
myEmitter.on('greet', (msg) => {
  console.log(' Event Received:', msg);
});
