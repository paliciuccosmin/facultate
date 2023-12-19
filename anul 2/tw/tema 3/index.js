var startTime = performance.now()
var canvas = document.getElementById("canvas");
var ctx = canvas.getContext("2d");

let dog = 
{
    "status": "success",
    "message": "https://images.dog.ceo/breeds/dingo/n02115641_9067.jpg"
}
canvas.width = 500;
canvas.height = 300;

var img = new Image();
img.crossOrigin = 'Anonymous';
img.src = dog.message;

img.onload = Process;

function Pause() {
    return new Promise(resolve => {
        setTimeout(() => {
            resolve('resolved');
        }, 1000);
    });
}


async function Process() {
    var mirroredImage = await mirrorImage(img);
    console.time("Execution time");
    await GrayScale(mirroredImage, 4);
    console.timeEnd("Execution time");
    await Pause();
    
    console.time("Execution time");
    await GrayScale(mirroredImage, 2.5);
    console.timeEnd("Execution time");
    await Pause();

    console.time("Execution time");
    await GrayScale(mirroredImage, 1.5);
    console.timeEnd("Execution time");
    await Pause();

    console.time("Execution time");
    await GrayScale(mirroredImage, 1);
    console.timeEnd("Execution time");
    await Pause();
}


function GrayScale(img, dash) {

    ctx.drawImage(img, 0, 0, canvas.width, canvas.height);
    var scannedImage = ctx.getImageData(0, 0, canvas.width, canvas.height);
    console.log(scannedImage);
    var scannedData = scannedImage.data;
    for (let i = 0 ; i < scannedData.length / dash ; i += 4) 
    {
        var total = scannedData[i] + scannedData[i + 1] + scannedData[i + 2]; 
        var averageColorValue = total / 3;

        scannedData[i] = averageColorValue;
        scannedData[i + 1] = averageColorValue;
        scannedData[i + 2] = averageColorValue;
    }
    scannedImage.data = scannedData;
    ctx.putImageData(scannedImage, 0, 0);


    var endTime = performance.now();
    ctx.font = "30px w";
}

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

            let a = data[index + 3];
            data[index + 3] = data[mirrorIndex + 3];
            data[mirrorIndex + 3] = a;

            a = data[index + 2];
            data[index + 2] = data[mirrorIndex + 2];
            data[mirrorIndex + 2] = a;

            a = data[index + 1];
            data[index + 1] = data[mirrorIndex + 1];
            data[mirrorIndex + 1] = a;

            a = data[index];
            data[index] = data[mirrorIndex];
            data[mirrorIndex] = a;
        }
    }
    ctx.putImageData(imageData, 0, 0);
    var mirroredImage = new Image();
    mirroredImage.src = canvas.toDataURL();
    return mirroredImage;
}