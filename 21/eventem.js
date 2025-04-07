const EventEmitter = require('events');

// Create an EventEmitter instance
const eventEmitter = new EventEmitter();

// Define an event handler for 'uptimeEvent'
eventEmitter.on('uptimeEvent', () => {
    console.log(`Application Uptime: ${process.uptime().toFixed(2)} seconds`);
});

// Emit 'uptimeEvent' every second
setInterval(() => {
    eventEmitter.emit('uptimeEvent');
}, 1000);