var startTime = performance.now();
var canvas = document.getElementById("canvas");
var ctx = canvas.getContext("2d");

async function getRandomDogImage() {
    try {
        const response = await fetch("https://dog.ceo/api/breeds/image/random");
        const data = await response.json();
        return data.message;
    } catch (error) {
        console.error("Error fetching dog image:", error);
        return null;
    }
}


async function loadImageAndProcess() {
    const dogImageUrl = await getRandomDogImage();

    if (!dogImageUrl) {
        return;
    }

    let dog = {
        "status": "success",
        "message": dogImageUrl
    };

    const jsonOutputDiv = document.getElementById("jsonOutput");
    jsonOutputDiv.textContent = JSON.stringify(dog, null, 2);

    var img = new Image();
    img.crossOrigin = 'Anonymous';
    img.src = dog.message;

    img.onload = () => {
        canvas.width = img.width;
        canvas.height = img.height;
        Process(img);
    };
}
//functie pentru timeout de 1 secunda intre operatii
function Pause(duration = 1000) {
    return new Promise(resolve => {
        setTimeout(() => {
            resolve('resolved');
        }, duration);
    });
}
//prelucrarea imaginii pe sectiuni
async function Process(img) {
    console.log("Original Image");
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.drawImage(img, 0, 0, canvas.width, canvas.height);
    await Pause();


    console.log("Mirrored Image");
    var mirroredImage = await mirrorImage(img);
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.drawImage(mirroredImage, 0, 0, canvas.width, canvas.height);
    
    await Pause();
    console.time("Execution time");
    await Contrast(mirroredImage, 4);
    console.timeEnd("Execution time");
    await Pause();

    console.time("Execution time");
    await Contrast(mirroredImage, 2);
    console.timeEnd("Execution time");
    await Pause();

    console.time("Execution time");
    await Contrast(mirroredImage, 1.5);
    console.timeEnd("Execution time");
    await Pause();

    console.time("Execution time");
    await Contrast(mirroredImage, 1);
    console.timeEnd("Execution time");
    await Pause();
}
//functie pentru a mentine valoarea pixelilor sub 255
function clamp(value) {
    return Math.min(255, Math.max(0, Math.round(value)));
}
//valoarea contrastului
var contrastFactor = 1.5;  
//functie pentru editarea pixelilor
function Contrast(img, dash) {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.drawImage(img, 0, 0, canvas.width, canvas.height);
    var scannedImage = ctx.getImageData(0, 0, canvas.width, canvas.height);
    var scannedData = scannedImage.data;
    for (let i = 0; i < scannedData.length/dash; i += 4) {
        scannedData[i] = clamp((scannedData[i] - 128) * contrastFactor + 128);
        scannedData[i + 1] = clamp((scannedData[i + 1] - 128) * contrastFactor + 128);
        scannedData[i + 2] = clamp((scannedData[i + 2] - 128) * contrastFactor + 128);
    }
    scannedImage.data = scannedData;
    ctx.putImageData(scannedImage, 0, 0);

    var endTime = performance.now();
    
}
//functia  de mirror
function mirrorImage(img) {
    var canvas = document.createElement("canvas");
    var ctx = canvas.getContext("2d");
    canvas.width = img.width;
    canvas.height = img.height;
    ctx.drawImage(img, 0, 0, img.width, img.height);
    var imageData = ctx.getImageData(0, 0, img.width, img.height);
    var data = imageData.data;

    for (let row = 0; row < img.height; row += 1) {
        for (let coll = 0; coll < img.width / 2; coll += 1) {
            let index = (row * img.width + coll) * 4;
            let mirrorIndex = ((img.width * (row + 1) - 1) * 4 - coll * 4);

            for (let i = 0; i < 4; i++) {
                let a = data[index + i];
                data[index + i] = data[mirrorIndex + i];
                data[mirrorIndex + i] = a;
            }
        }
    }
    ctx.putImageData(imageData, 0, 0);
    var mirroredImage = new Image();
    mirroredImage.src = canvas.toDataURL();
    return mirroredImage;
}


loadImageAndProcess();
