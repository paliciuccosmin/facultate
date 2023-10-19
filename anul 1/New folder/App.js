import React, { useState } from "react";

function App() {
  const [mod, setMod] = useState(0);
  const [inputValue, setInputValue] = useState("");
  const [outputValue, setOutputValue] = useState("");

  const handleModChange = (event) => {
    setMod(parseInt(event.target.value, 10));
    setInputValue("");
    setOutputValue("");
  };

  const handleInputChange = (event) => {
    setInputValue(event.target.value);
    setOutputValue("");
  };

  const handleEncryptClick = () => {
    let encrypted = "";
    for (let i = 0; i < inputValue.length; i++) {
      const c = inputValue.charAt(i);
      if (c >= "a" && c <= "z") {
        if (c === "a") {
          encrypted += "0";
        } else {
          encrypted += (c.charCodeAt(0) - "a".charCodeAt(0)) + " ";
        }
      } else if (c >= "A" && c <= "Z") {
        if (c === "A") {
          encrypted += "0";
        } else {
          encrypted += (c.charCodeAt(0) - "A".charCodeAt(0)) + " ";
        }
      } else {
        encrypted += c;
      }
    }
    setOutputValue(encrypted);
  };

  const handleDecryptClick = () => {
    const inputArr = inputValue.split(" ");
    let decrypted = "";
    for (let i = 0; i < inputArr.length; i++) {
      const num = parseInt(inputArr[i], 10);
      if (!isNaN(num)) {
        decrypted += String.fromCharCode(num + "A".charCodeAt(0));
      } else {
        decrypted += inputArr[i];
      }
    }
    setOutputValue(decrypted);
  };

  const renderInputField = () => {
    if (mod === 1) {
      return (
        <div>
          <label htmlFor="input">Introduceti cuvantul:</label>
          <br />
          <input type="text" id="input" value={inputValue} onChange={handleInputChange} />
        </div>
      );
    } else if (mod === 2) {
      return (
        <div>
          <label htmlFor="input">Numerele:</label>
          <br />
          <input type="text" id="input" value={inputValue} onChange={handleInputChange} />
        </div>
      );
    } else {
      return null;
    }
  };

  return (
    <div>
      <h1>Enigma</h1>
      <div>
        <label htmlFor="mod">Actiunea dorita:</label>
        <br />
        <select id="mod" value={mod} onChange={handleModChange}>
          <option value={0}>-- Selectati --</option>
          <option value={1}>Criptare</option>
          <option value={2}>Decriptare</option>
          <option value={3}>Stop</option>
        </select>
      </div>
      {renderInputField()}
      <br />
      <button onClick={mod === 1 ? handleEncryptClick : handleDecryptClick}>
        {mod === 1 ? "Cripteaza" : "Decripteaza"}
      </button>
      <br />
      <div>
        <label htmlFor="output">Rezultat:</label>
        <br />
        <div>
          <label htmlFor="output">Rezultat:</label>
          <br />
          <textarea id="output" value={outputValue} readOnly></textarea>
        </div>
      </div>
    </div>
  );
}
export default App;