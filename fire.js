var firebase = require('firebase')
// datos de firebase
var config = {

  apiKey: "AIzaSyAFSMbZ3kbr4i7ITJmJe28xyX0F65eAeSw",

  authDomain: "proyectclima.firebaseapp.com",

  databaseURL: "https://proyectclima-default-rtdb.firebaseio.com",

  projectId: "proyectclima",

  storageBucket: "proyectclima.appspot.com",

  messagingSenderId: "982720757168",

  appId: "1:982720757168:web:b29fc7b7f3ab02e09d2a75"
};

const fire = firebase.initializeApp(config);
module.exports = fire;
