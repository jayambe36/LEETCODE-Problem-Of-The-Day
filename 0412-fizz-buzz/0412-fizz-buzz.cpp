class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> fizzBuzz;
        string temp;
            for(int i=1; i <=n; i++){
                string temp = "";
                if( i % 3 == 0 || i % 5 == 0){
                    if( i % 3 == 0 )
                        temp = "Fizz";
                    if ( i % 5 == 0)
                        temp = temp + "Buzz";
                }
                else
                    temp = to_string(i);
                fizzBuzz.push_back(temp);
            }
        return fizzBuzz;
    }
};


// class Solution {
// public:
//     vector<string> fizzBuzz(int n) {
//       List<String> answer = new ArrayList<>(n);
        
//         for(int i=1; i<=n; i++){
//             boolean divisibleBy3 = i%3 == 0;
//             boolean divisibleBy5 = i%5 == 0;
            
//             String currStr = "";
            
//             if(divisibleBy3) {
//                 currStr = currStr + "Fizz";
//             }
            
//             if(divisibleBy5) {
//                 currStr = currStr + "Buzz";
//             }
            
//             if(currStr.isEmpty())
//             {
//                 currStr = currStr + String.valueOf(i);
//             }
            
//             answer.add(currStr);
//         }
//         return answer;
// };