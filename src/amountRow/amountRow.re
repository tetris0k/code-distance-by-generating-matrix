[%bs.raw {|require('./amountRow.css')|}];

let component = ReasonReact.statelessComponent "AmountRow";

let make ::title ::value ::incValue ::decValue ::incDisabled=false ::decDisabled=false _children => {
  let increase _event _self => incValue ();
  let decrease _event _self => decValue ();
  {
    ...component,
    render: fun self =>
      <div className="amount-row">
        <button onClick=(self.handle increase) disabled=(Js.Boolean.to_js_boolean incDisabled)>
          (ReasonReact.stringToElement "+")
        </button>
        <button onClick=(self.handle decrease) disabled=(Js.Boolean.to_js_boolean decDisabled)>
          (ReasonReact.stringToElement "-")
        </button>
        (ReasonReact.stringToElement (title ^ ": " ^ string_of_int value))
      </div>
  }
};
