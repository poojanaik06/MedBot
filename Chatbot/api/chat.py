from flask import Flask, request, jsonify
import subprocess

app = Flask(__name__)

@app.route('/api/chat', methods=['POST'])
def chat():
    user_input = request.json['input']
    try:
        # Run the C program
        process = subprocess.Popen(['/Chatbot/chatbot.C'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout, stderr = process.communicate(input=user_input.encode())
        if stderr:
            return jsonify({'error': stderr.decode()}), 500
        return jsonify({'response': stdout.decode()})
    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    app.run(debug=True)
