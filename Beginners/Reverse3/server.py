from flask import Flask, request, jsonify
from Crypto.Util.number import bytes_to_long, long_to_bytes

app = Flask(__name__)

konami_code = "up   up   down down left right left right B    A    "

@app.route("/adminSupport", methods=["GET", "POST"])
def support():
    
    if request.method == "GET":
        return jsonify({"response": konami_code}), 200
    if request.method == "POST":
        data = request.get_json()
        if data["code"] == konami_code:
            return jsonify({"response": "pascalCTF{M3t4l_G34r_15_k1Nd4_G04t3d}"}), 200
        else:
            return jsonify({"response": "Skill Issue"}), 200

if __name__ == "__main__":
    app.run(debug=True)