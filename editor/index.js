let canvas = document.querySelector("#canvas");
let ctx = canvas.getContext("2d");
let curCol = 1;
let saveText = document.querySelector("#save");

const tileSize = 16;
const gridSize = 1;
const levelSize = {
  x: 40,
  y: 30
};
let spawnPos = {
  x: 0,
  y: 0
};
let spawnSize = 10;

let tiles = [];
for (let y = 0; y < levelSize.y; y++) {
  let arr = [];
  for (let x = 0; x < levelSize.x; x++) {
    arr.push(curCol);
  }
  tiles.push(arr);
}

const roundDown = (num, multiple) => {
  if (multiple === 0) {
    return num;
  }
  
  let remainder = num % multiple;
  if (remainder === 0) {
    return num;
  } else {
    return num - remainder;
  }
};

// Draw tiles
const drawTiles = (tiles, ctx) => {
  // Grid background
  ctx.fillStyle = "rgb(0, 0, 0)";
  ctx.fillRect(0, 0, 640, 480);
  for (let y = 0; y < tiles.length; y++) {
    for (let x = 0; x < tiles[y].length; x++) {
      switch (tiles[y][x]) {
        case 0:
          ctx.fillStyle = 'rgb(96, 155, 66)';
          break;
        case 1:
          ctx.fillStyle = 'rgb(0, 123, 157)';
          break;
        case 2:
          ctx.fillStyle = 'rgb(218, 129, 39)';
          break;
      } // \switch
      
      // Draw square
      ctx.fillRect(
        x * tileSize + gridSize,
        y * tileSize + gridSize,
        tileSize - gridSize,
        tileSize - gridSize
      );
    }
    
    // Draw spawn
    ctx.fillStyle = 'rgb(255, 0, 0)';
    ctx.fillRect(
      (spawnPos.x * tileSize) + (tileSize / 4),
      (spawnPos.y * tileSize) + (tileSize / 4),
      spawnSize,
      spawnSize * 2.5
    );
  }
};

// Places a tile
const placeTile = e => {
  let pos = getMouse(e);
  pos.x = roundDown(pos.x, tileSize) / tileSize;
  pos.y = roundDown(pos.y, tileSize) / tileSize;
  if (curCol == 'spawn') {
    spawnPos = pos;
  } else {
    tiles[pos.y][pos.x] = curCol;
  }
  save(tiles);
  drawTiles(tiles, ctx);
};

// Get's mouse coordinates
const getMouse = e => {
  let rect = canvas.getBoundingClientRect();
  return {
    x: e.clientX - rect.left,
    y: e.clientY - rect.top
  };
};

let mouseDown = false;

// Get mouse clicks
canvas.addEventListener("mousedown", e => {
  mouseDown = true;
  placeTile(e);
});

canvas.addEventListener("mousemove", e => {
  if (mouseDown) {
    placeTile(e);
  }
});

canvas.addEventListener("mouseup", () => {
  mouseDown = false;
});

const save = tiles => {
  let saveTiles = [];
  for (let y = 0; y < levelSize.y; y++) {
    saveTiles.push(tiles[y].join(" "));
  }
  saveText.value = `${spawnPos.x} ${spawnPos.y}\n${saveTiles.join('\n')}`;
};

const clear = (tiles, tile) => {
    for (var y = 0; y < tiles.length; y++) {
        for (var x = 0; x < tiles[y].length; x++) {
            tiles[y][x] = tile;
        }
    }
    drawTiles(tiles, ctx);
}

const buttons = document.querySelectorAll('input[type=radio][name=tile]');
for (let button of buttons) {
  button.addEventListener('change', e => {
    let checkButton = document.querySelector('input[type=radio]:checked');
    if (checkButton.getAttribute('value') == 'spawn') {
      curCol = 'spawn';
    } else {
      curCol = Number(checkButton.value);
    }
  });
}

drawTiles(tiles, ctx);
