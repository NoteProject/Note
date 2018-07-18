var mongoose = require('mongoose');
var config = require('./config.js');

module.exports = function() {
    var db = mongoose.connect(config.mongodb, { useNewUrlParser: true }).catch(function (e) {
        console.log(e)
    });

    console.log("DB INIT SUCCESSFUL")

    require('../models/user.server.model.js');
    return db;
}