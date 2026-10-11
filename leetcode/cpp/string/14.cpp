/**
 * 14. Longest Common Prefix
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 */

/**
 * example 1:
 * input: str = [ "flower", "flow", "flight" ]
 * output: "fl"
 *
 *
 @author of the code is vi (yeah that's the nickname
 */

class Solution {
    constexpr static size_t THE_PREFIX_START_{0};

public:
    constexpr inline std::string longestCommonPrefix(const std::vector<std::string>& strs) noexcept {
        std::string common_prefix{strs[0]};

        // iterating through every string in strs
        // e stands for element
        for(const auto& e : strs) {
            // if we didn't find the prefix, we'll change the prefix until we found it
            while(e.find(common_prefix) != THE_PREFIX_START_) {
                common_prefix = common_prefix.substr(0, common_prefix.size()-1);
                // if common_prefix is an empty string, than it's over
                if(common_prefix.empty()) {
                    return "";
                }
            }
        }

        return common_prefix;
    }
};
