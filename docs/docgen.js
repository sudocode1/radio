const cond = [['cond', 'The condition.']];
const varDef = [['name', 'The variable\'s name.'], ' = ', ['value', 'The variable\'s value.']];

const data = [
    ['end', 'Ends a statement.'],
    ['out', 'Outputs text without a newline.'],
    ['out!', 'Outputs text with a newline.'],
    ['@nl', 'Prints a newline.'],
    ['@strout', 'Outputs a string variable.'],
    ['@intout', 'Outputs an int variable.'],
    ['@floatout', 'Outputs a float variable.'],
    ['@!define', 'Defines a function without parameters.'],
    [
        '@define',
        'Defines a function.',
        [
            ['returnType', 'The function\'s return type.'],
            ['name', 'The function\'s name.']
        ],
        [0, 1].map(x => [
            `@${['', 'final'][x]}param`,
            `Adds ${['a', 'the final'][x]} parameter. ${['', 'If a parameter isn\'t directly followed by another one, it\'s required to use @finalparam.'][x]}`,
            [['type', 'The param\'s type.'], ['name', 'The param\'s name.']],
        ]),
    ],
    ...[0, 1].map(x => [`@${['!', ''][x]}call`, `Calls a function with ${['no', 'the specified'][x]} params`, [['fn', 'The function\'s name'], ...(x ? [['...params', 'A list of parameters, seperated by commas.']] : [])]]),
    ...[['int', 'number'], ['str', 'string'], ['double', 'double']].map(x => ['@' + x[0], `Defines a ${x[1]} variable.`, varDef]),
    ['for', 'Adds a for loop.', [['decl', 'The variable declaration.'], '; ', cond[0], '; ', ['step', 'The statement which gets executed after each iteration.']]],
    ['if', 'Adds an if statement.', cond, ['else if', 'elif', 'else'].map(x => [x, `Adds an ${x === 'elif' ? 'else if' : x} statement.`, cond])],
    ['while', 'Adds a while statement.', cond],
    ['@redefine', 'Redefines an already existing variable.', varDef],
    ['@structure', 'Start a structure.'],
    ['@struct_access_property', 'Output a structure property.', [['type', 'The property type.'], ['variable.property', 'The variable and the property you want to output.']]],
    ['@create_struct', 'Create a variable based on a structure.', [['struct', 'The structure name.'], ['name', 'The variable name.']]],
    ['@endstructure', 'End a structure definition.'],
    ['@property', 'Add a structure property (within structure definition).', [['type', 'The property type.'], ['name', 'The property name.']]]
];
// invalid ratio detected
const render = (a, indent) => a.map(x => `${'#'.repeat(indent)} ${x[0]}
- ${x[1]}
- Usage: ${x[0]} ${console.log(x) || (x[2] || []).reduce((a, b, i) => a + (typeof b === 'string' ? '' : b[0] + (typeof x[2][i + 1] === 'string' ? x[2][i + 1] : i < x[2].length - 1 ? ' ' : '')), '')}${x[2] ? `
- Parameters
${x[2].filter(x => typeof x !== 'string').map(x => `  - ${x[0]} - ${x[1]}`).join('\n')}` : ''}${x[3] ? `
- Sub-methods
${render(x[3], indent + 1)}` : ''}`).map(x => x.split('\n').map(x => ' '.repeat((indent - 1) * 2) + x).join('\n')).join(indent < 2 ? '\n' : '\n\n');
require('fs').writeFileSync('./DOCS.md', render(data, 1));