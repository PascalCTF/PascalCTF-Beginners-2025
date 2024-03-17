#!/usr/bin/env python3
from flask import Flask, render_template, render_template_string
from flask_mysqldb import MySQL
import os

app = Flask(__name__)
app.config['MYSQL_HOST'] = os.getenv('MYSQL_HOST', 'localhost')
app.config['MYSQL_USER'] = os.getenv('MYSQL_USER', 'root')
app.config['MYSQL_PASSWORD'] = os.getenv('MYSQL_PASSWORD', 'password')
app.config['MYSQL_DB'] = os.getenv('MYSQL_DB', 'mydb')
mysql = MySQL(app)

@app.errorhandler(404)
@app.route('/<path:path>')
def page_not_found(path):
    with open('../templates/404.html', 'r') as file:
        ERROR = file.read()
    return render_template_string(ERROR.format(path))

@app.route('/')
def index():
    return render_template('index.html')

if __name__ == '__main__':
    app.run('0.0.0.0', '5000', debug=False)