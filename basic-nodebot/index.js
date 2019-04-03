import {Board, Led, Button} from 'johnny-five';

// Make variables for objects we'll be using

// Set `lightOn` to true as a default since our LED will be on
let lightOn = true;

// Make a new Board Instance
const board = new Board();

// When the board is connected, turn on the LED connected to pin 9
board.on('ready', function() {
  console.log('[johnny-five] Board is ready.');

  // Make a new Led object and connect it to pin 9
  const led = new Led(9);

  // Make a new Button object assigned to pin 7
  // We also need to say it is a pullup resistor!
  const pushButton = new Button({
    pin: 7,
    isPullup: true,
  });

  // Switch it on!
  led.on();

  // If the button is pressed, toggle the LED on or off
  pushButton.on('down', () => {
    if (lightOn) {
      led.off();
      lightOn = false;
    } else {
      led.on();
      lightOn = true;
    }
  });

  // REPL object so we can interact with our LED
  this.repl.inject({
    // Control the LED via calling for the object
    led,
    // switchOn and switchOff functions to turn LED on and off using REPL
    switchOn: () => {
      if (lightOn) {
        console.log('[johnny-five] LED is already on!');
      } else {
        led.on();
        lightOn = true;
      }
    },
    switchOff: () => {
      if (!lightOn) {
        console.log('[johnny-five] LED is already off!');
      } else {
        led.stop().off();
        lightOn = false;
      }
    },
  });

  // When the board is closing, stop any LED animations and turn it off
  this.on('exit', () => {
    led.stop().off();
    console.log('[johnny-five] Bye Bye.');
  });

});
