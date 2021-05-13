switch ReactDOM.querySelector("#app") {
| Some(element) => ReactDOM.render(<App />, element)
| None => ()
}
