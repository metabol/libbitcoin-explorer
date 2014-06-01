/*
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <iostream>
#include <bitcoin/bitcoin.hpp>
#include <wallet/wallet.hpp>

using namespace bc;
using namespace libwallet;

std::string dump_file(std::istream& in_file)
{
    std::istreambuf_iterator<char> it(in_file);
    std::istreambuf_iterator<char> end;
    return std::string(it, end);
}

int main()
{
    std::string secret_str = dump_file(std::cin);
    secret_parameter secret = decode_hash(secret_str);
    std::cout << secret_to_wif(secret) << std::endl;
    return 0;
}
