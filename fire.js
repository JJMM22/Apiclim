var firebase = require('firebase')
// datos de firebase
var config = {

  apiKey: "AIzaSyB-BCUnOF-R5qSYSs05xMaKT1yjlURemeE",

  authDomain: "apiclima-dc114.firebaseapp.com",

  databaseURL: "https://apiclima-dc114-default-rtdb.firebaseio.com",

  projectId: "apiclima-dc114",

  storageBucket: "apiclima-dc114.appspot.com",

  messagingSenderId: "912064105443",

  appId: "1:912064105443:web:869138e218d8854628eed6"
};

const fire = firebase.initializeApp(config);
module.exports = fire;
