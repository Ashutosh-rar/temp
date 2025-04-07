
function delayedOperation() {
    return new Promise((resolve) => {
        setTimeout(() => {
            resolve("Operation completed successfully!");
        }, 3000); 
    });
}


async function executeTask() {
    console.log("Waiting for the promise to return a result...");
    
    const result = await delayedOperation(); 
    
    console.log("Result:", result);
}


executeTask();