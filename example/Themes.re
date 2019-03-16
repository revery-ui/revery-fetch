open Revery;

type theme = {
  overallBackgroundColor: Color.t,
  postBackgroundColor: Color.t,
  postTextColor: Color.t,
};

let regular = () => {
  overallBackgroundColor: Color.hex("#f2f3f5"),
  postBackgroundColor: Colors.white,
  postTextColor: Colors.black,
};

let dark = () => {
  overallBackgroundColor: Colors.black,
  postBackgroundColor: Color.hex("#111111"),
  postTextColor: Colors.white,
};

let generalFontSize = 13;
let currentTheme = ref(regular());
