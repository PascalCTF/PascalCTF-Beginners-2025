from flask import Flask, request, jsonify
import os

app = Flask(__name__)

code = "up-up-down-down-left-right-left-right-B-A"

@app.route("/adminSupport", methods=["GET", "POST"])
def support():
    if request.method == "GET":
        return jsonify({"response": code}), 200
    if request.method == "POST":
        data = request.get_json()
        if data["code"] == code:
            return os.getenv('FLAG', 'pascalCTF{M3t4l_G34r_15_k1Nd4_G04t3d}'), 200
        else:
            return "Skill Issue", 403

if __name__ == "__main__":
    app.run('0.0.0.0', 5000, debug=False)