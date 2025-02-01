const { exec } = require('child_process');
const path = require('path');

module.exports = async (req, res) => {
    const userInput = req.body.input;

    // Path to your C executable
    const chatbotPath = path.join(__dirname, '..', 'chatbot');

    // Run the C program
    exec(`${chatbotPath}`, { input: userInput }, (error, stdout, stderr) => {
        if (error) {
            console.error(`Error: ${error.message}`);
            return res.status(500).json({ error: 'Internal Server Error' });
        }
        if (stderr) {
            console.error(`Stderr: ${stderr}`);
            return res.status(500).json({ error: 'Internal Server Error' });
        }
        // Send the chatbot's response back to the frontend
        res.status(200).json({ response: stdout });
    });
};
