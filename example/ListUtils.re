let rec firstN = (n, xs) =>
  switch (xs) {
  | [] => []
  | [x, ...xs] =>
    if (n == 1) {
      [x];
    } else {
      [x, ...firstN(n - 1, xs)];
    }
  };