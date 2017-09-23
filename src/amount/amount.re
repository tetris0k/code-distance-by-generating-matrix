type action =
  | IncHeight
  | DecHeight
  | IncWidth
  | DecWidth;

type state = {
  height: int,
  width: int
};

let component = ReasonReact.reducerComponent "Amount";

let make _children => {
  ...component,
  initialState: fun () => {height: 1, width: 2},
  reducer: fun action state =>
    switch action {
    | IncHeight => ReasonReact.Update {...state, height: state.height + 1}
    | DecHeight => ReasonReact.Update {...state, height: state.height - 1}
    | IncWidth => ReasonReact.Update {...state, width: state.width + 1}
    | DecWidth => ReasonReact.Update {...state, width: state.width - 1}
    },
  render: fun self => {
    let isHeightDecDisabled = self.state.height < 2;
    let isHeightIncDisabled = self.state.height >= self.state.width - 1;
    let isWidthDecDisabled = self.state.width <= self.state.height + 1;
    let incHeight () => self.reduce (fun _event => IncHeight);
    let decHeight () => self.reduce (fun _event => DecHeight);
    let incWidth () => self.reduce (fun _event => IncWidth);
    let decWidth () => self.reduce (fun _event => DecWidth);
    <div>
      <AmountRow
        title="Height"
        value=self.state.height
        incValue=(self.handle incHeight)
        decValue=(self.handle decHeight)
        incDisabled=isHeightIncDisabled
        decDisabled=isHeightDecDisabled
      />
      <AmountRow
        title="Width"
        value=self.state.width
        incValue=(self.handle incWidth)
        decValue=(self.handle decWidth)
        decDisabled=isWidthDecDisabled
      />
    </div>
  }
};
