[%bs.raw {|require('./app.css')|}];

external logo : string = "../logo.svg" [@@bs.module];

let component = ReasonReact.statelessComponent "App";

let make _children => {
  ...component,
  render: fun _self =>
    <div className="App">
      <div className="App-header"> <h2> (ReasonReact.stringToElement "Code matrix") </h2> </div>
      <Amount />
    </div>
};
