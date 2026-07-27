self.onmessage = (url) => {
  fetch("https://dummyjson.com/users")
    .then((res) => {
      return res.json();
    })
    .then((data) => self.postMessage({ res: data, error: "null" }))
    .catch((err) => self.postMessage({ res: "", error: err }));
};
