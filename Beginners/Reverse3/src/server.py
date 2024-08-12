from flask import Flask, request, jsonify
import os

app = Flask(__name__)

konami_code = "up-up-down-down-left-right-left-right-B-A"

@app.route("/adminSupport", methods=["GET", "POST"])
def support():
    if request.method == "GET":
        return jsonify({"response": konami_code}), 200
    if request.method == "POST":
        data = request.get_json()
        if data["code"] == konami_code:
            return os.getenv('FLAG'), 200
        else:
            return "Skill Issue", 403

if __name__ == "__main__":
    app.run(debug=True)