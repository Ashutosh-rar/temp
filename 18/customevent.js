const EventEmitter = require('events'); 
class MyEmitter extends EventEmitter {} 
const myEmitter = new MyEmitter(); 


function data_receive_handler(data) { 
  console.log(`Custom Event - Data received: ${data}`); 
} 


myEmitter.on('receive_data', data_receive_handler); 

 
myEmitter.on('dataReceived', (data) => { 
  console.log(`Data received: ${data}`); 
}); 


myEmitter.on('errorOccurred', (error) => { 
  console.error(`An error occurred: ${error}`); 
}); 


setInterval(() => { 
  const eventType = Math.random() > 0.5 ? 'dataReceived' : 'errorOccurred'; 
  if (eventType === 'dataReceived') { 
    myEmitter.emit('dataReceived', 'Sample Data'); 
    myEmitter.emit('receive_data', 'Custom Sample Data'); 
  } else { 
    myEmitter.emit('errorOccurred', 'Sample Error'); 
  } 
}, 2000);


//run node customevent.js